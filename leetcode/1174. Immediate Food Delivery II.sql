WITH cte AS (
	SELECT
		ROW_NUMBER() OVER (PARTITION BY customer_id ORDER BY order_date) AS r_num,
		CASE WHEN order_date = customer_pref_delivery_date THEN 100 ELSE 0 END AS immediate_order_flag
	FROM
		Delivery
)
SELECT ROUND(AVG(immediate_order_flag), 2) AS immediate_percentage
FROM cte
WHERE r_num = 1;
