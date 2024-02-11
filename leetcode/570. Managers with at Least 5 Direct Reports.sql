SELECT manager.name
FROM Employee AS manager
INNER JOIN Employee AS emp
ON manager.id = emp.managerId
GROUP BY manager.id
HAVING COUNT(emp.id) >= 5
