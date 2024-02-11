SELECT r.contest_id, ROUND(
    COUNT(u.user_id) / 
    (SELECT COUNT(user_id) FROM Users),
    4
) * 100 AS "percentage"
FROM Register AS r
INNER JOIN Users AS u
ON u.user_id = r.user_id
GROUP BY r.contest_id
ORDER BY percentage DESC, r.contest_id ASC

-- WITH userCount AS (
--     SELECT COUNT(user_id) AS "total"
--     FROM Users
-- )
-- SELECT r.contest_id, ROUND(COUNT(u.user_id) / uc.total, 4) * 100 AS "percentage"
-- FROM Register AS r
-- INNER JOIN Users AS u
-- ON u.user_id = r.user_id
-- CROSS JOIN userCount AS uc
-- GROUP BY r.contest_id
-- ORDER BY COUNT(u.user_id) DESC, r.contest_id ASC 
