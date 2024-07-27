SELECT query_name, 
ROUND(SUM(rating/position) / count(result), 2) AS 'quality',
ROUND(SUM(
    CASE WHEN rating < 3 THEN 1
    ELSE 0
    END
) / COUNT(result), 4) * 100 as "poor_query_percentage"
FROM Queries
where query_name is not null
group by query_name
