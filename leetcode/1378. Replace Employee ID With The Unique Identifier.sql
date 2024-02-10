# Write your MySQL query statement below
SELECT eu.unique_id, e.name
FROM Employees AS e
LEFT JOIN EmployeeUNI eu
ON e.id = eu.id

