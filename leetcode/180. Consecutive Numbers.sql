SELECT DISTINCT l1.num AS "ConsecutiveNums"
FROM Logs AS l1
INNER JOIN Logs AS l2 ON l2.num = l1.num
INNER JOIN Logs AS l3 ON l3.num = l1.num
WHERE l1.id = l2.id + 1 AND l2.id = l3.id + 1;
