SELECT
    p.product_id, 
    COALESCE(ROUND(SUM(p.price * us.units) / SUM(us.units), 2), 0) AS "average_price"
FROM Prices AS p
LEFT JOIN UnitsSold AS us
ON p.product_id = us.product_id
WHERE us.purchase_date IS NULL OR us.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY p.product_id;

--  WITH t AS (
--      SELECT p.product_id, SUM(p.price * us.units) AS "av", SUM(us.units) AS "su"
--      FROM Prices AS p
--      LEFT JOIN UnitsSold AS us
--      ON p.product_id = us.product_id
--      WHERE us.product_id IS NULL OR us.purchase_date BETWEEN p.start_date AND p.end_date
--      GROUP BY p.product_id, p.start_date, p.end_date
--  )
--  SELECT 
--      t.product_id,
--      COALESCE(ROUND(SUM(t.av) / SUM(t.su), 2), 0) AS "average_price"
--  FROM t
--  GROUP BY t.product_id
