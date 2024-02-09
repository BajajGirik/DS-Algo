SELECT DISTINCT l1.num AS "ConsecutiveNums"
FROM Logs AS l1
INNER JOIN Logs AS l2
ON l1.num = l2.num
INNER JOIN Logs AS l3
ON l1.num = l3.num
WHERE 
    l2.id > l1.id AND
    l3.id > l2.id AND
    l2.id = l1.id + 1 AND
    l3.id = l2.id + 1
