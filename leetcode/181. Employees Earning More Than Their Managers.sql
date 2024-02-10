SELECT emp.name AS "Employee"
FROM Employee AS emp
INNER JOIN Employee AS manager
ON manager.id = emp.managerId
WHERE 
  emp.managerId IS NOT NULL AND
  emp.salary > manager.salary;
