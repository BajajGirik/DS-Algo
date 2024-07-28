WITH firstSoldYearForProduct AS (
	SELECT
		product_id,
		MIN(`year`) first_year
	FROM
		Sales
	GROUP BY
		product_id
)
SELECT
	fsyfp.product_id,
	fsyfp.first_year,
	s.quantity,
	s.price
FROM
	firstSoldYearForProduct fsyfp
	INNER JOIN Sales s ON s.product_id = fsyfp.product_id
		AND s. `year` = fsyfp.first_year;
