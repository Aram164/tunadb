# MATCH_RECOGNIZE in DuckDB

Diese Datei dokumentiert den aktuellen Stand der `MATCH_RECOGNIZE`-Implementierung in diesem Projekt.
Die Semantik orientiert sich an Trino, aber der tatsächlich unterstützte Umfang ist der in diesem Branch implementierte.

## Überblick

`MATCH_RECOGNIZE` erkennt Zeilenmuster in sortierten Daten.
Typische Einsatzfälle sind:

- Aktienverläufe und Trendwechsel
- Sensor-Spitzen und Erholungsphasen
- Web-Session-Funnels

Die mitgelieferten Beispielskripte liegen in diesem Ordner:

- [stocks_v_shape.sql](/Users/aramaljanadi/Desktop/SemesterProjekt/tunadb/docs/stocks_v_shape.sql)
- [sensor_spike_recovery.sql](/Users/aramaljanadi/Desktop/SemesterProjekt/tunadb/docs/sensor_spike_recovery.sql)
- [web_session_funnel.sql](/Users/aramaljanadi/Desktop/SemesterProjekt/tunadb/docs/web_session_funnel.sql)

## Unterstützte Syntax

```sql
FROM table_name MATCH_RECOGNIZE (
    [PARTITION BY expr [, expr ...]]
    ORDER BY expr
    MEASURES measure_expr AS alias [, measure_expr AS alias ...]
    [ONE ROW PER MATCH | ALL ROWS PER MATCH]
    AFTER MATCH SKIP PAST LAST ROW
      | AFTER MATCH SKIP TO NEXT ROW
    [WITHIN interval_expr]
    PATTERN ('pattern')
    DEFINE var AS boolean_expr [, var AS boolean_expr ...]
)
```

Wichtige Punkte:

- `ORDER BY` ist Pflicht.
- Aktuell wird genau ein `ORDER BY`-Ausdruck erwartet.
- `MEASURES` ist Pflicht.
- `AFTER MATCH SKIP` ist Pflicht.
- `PATTERN` ist Pflicht.
- `DEFINE` ist Pflicht.
- `WITHIN` ist optional.

## PATTERN

Unterstützt werden:

- Konkatenation: `A B C`
- Alternation: `A | B`
- Gruppierung: `(A B)+`
- Quantifier: `*`, `+`, `?`

Aktuelle wichtige Einschränkung:

- Pattern-Variablen sind in diesem Branch auf **ein Zeichen** beschränkt, also z. B. `A`, `B`, `D`.

## DEFINE

`DEFINE` ordnet Variablen boolesche Bedingungen zu.

Beispiele:

```sql
DEFINE
    D AS price < PREV(price),
    U AS price > PREV(price)
```

Unterstützt:

- normale boolesche Ausdrücke
- `PREV(col)` innerhalb einer Partition

Semantik:

- Für die erste Zeile einer Partition liefert `PREV(col)` `NULL`.
- `NULL` in `DEFINE` zählt als `false`.
- Pattern-Variablen ohne eigenen `DEFINE`-Eintrag verhalten sich wie Wildcards.

## MEASURES

Unterstützt werden:

- `var.col`
- `FIRST(var.col)`
- `LAST(var.col)`
- `COUNT(*)`
- `COUNT(var.*)`
- `MIN(var.col)`
- `MAX(var.col)`
- `SUM(var.col)`
- `AVG(var.col)`

Beispiel:

```sql
MEASURES
    A.ts AS start_ts,
    LAST(B.ts) AS end_ts,
    COUNT(B.*) AS steps
```

Aktuelle wichtige Einschränkung:

- In diesem Branch ist `AS alias` für `MEASURES` praktisch Pflicht.

## ROWS PER MATCH

Unterstützt:

- `ONE ROW PER MATCH`
- `ALL ROWS PER MATCH`

## AFTER MATCH SKIP

Unterstützt:

- `AFTER MATCH SKIP PAST LAST ROW`
- `AFTER MATCH SKIP TO NEXT ROW`

Leere Matches werden verworfen.

## WITHIN

`WITHIN` begrenzt die maximale Dauer eines Matches zwischen erster und letzter Match-Zeile.

Beispiel:

```sql
WITHIN 10 MINUTE
```

Aktueller Stand:

- `WITHIN` muss zu einem konstanten `INTERVAL` auswertbar sein.
- `ORDER BY` muss auf einer Zeit-/Datums-Spalte liegen:
  `DATE`, `TIME`, `TIME_TZ`, `TIMESTAMP`, `TIMESTAMP_TZ`

## Bekannte Limitierungen

- Pattern-Variablen sind nur ein Zeichen lang.
- Es gibt keinen separaten Pattern-AST im DuckDB-AST; das Pattern wird als String gehalten und später für die NFA geparst.
- Nicht unterstützt sind u. a. `{m,n}`, `SUBSET`, `PERMUTE`, `CLASSIFIER()`, `MATCH_NUMBER()`.
- `MEASURES` ist auf die oben genannten Formen beschränkt.

## Typische Fehlermeldungen

- `MATCH RECOGNIZE: missing ORDER BY clause`
- `MATCH RECOGNIZE: missing MEASURES clause`
- `MATCH RECOGNIZE: missing AFTER MATCH SKIP clause`
- `MATCH RECOGNIZE: missing PATTERN clause`
- `MATCH RECOGNIZE: missing DEFINE clause`
- `MATCH_RECOGNIZE ORDER BY must be a total order (no ties)`
- `WITHIN requires ORDER BY on a time or date column`

## Beispiele

Die drei SQL-Dateien in diesem Ordner sind reproduzierbare Beispiele für:

- Aktien-V-Form
- Sensor-Spike mit Erholung
- Web-Session-Funnel
