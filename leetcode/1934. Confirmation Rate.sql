SELECT s.user_id,
    COALESCE(Round(Count(CASE
                            WHEN c.action = 'confirmed' THEN c.user_id
                            ELSE NULL
                            END) / Count(c.user_id), 2), 0) AS
       'confirmation_rate'
FROM signups AS s
LEFT JOIN confirmations AS c
ON s.user_id = c.user_id
GROUP  BY s.user_id; 
