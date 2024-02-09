CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE _offset INT;
  SET _offset = N-1;
  RETURN (
      SELECT COALESCE (
          (
              SELECT DISTINCT salary 
              FROM Employee
              ORDER BY salary DESC
              LIMIT 1 OFFSET _offset
          ), 
          NULL
      )
  );
END

