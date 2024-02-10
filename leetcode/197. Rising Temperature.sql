# Write your MySQL query statement below
SELECT w.id
FROM Weather AS w
INNER JOIN Weather prevW
ON DATEDIFF(w.recordDate, prevW.recordDate) = 1
WHERE w.temperature > prevW.temperature;
