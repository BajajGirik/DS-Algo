SELECT 
    manager.employee_id,
    manager.name,
    COUNT(emp.reports_to) AS "reports_count",
    ROUND(AVG(emp.age)) AS "average_age"
FROM Employees AS manager
INNER JOIN Employees AS emp ON manager.employee_id = emp.reports_to
GROUP BY manager.employee_id, manager.name
ORDER BY manager.employee_id;
