WITH playerStartDates AS (
	SELECT
		player_id,
		MIN(event_date) AS event_date
	FROM
		Activity
	GROUP BY
		player_id
)
SELECT
	ROUND(
		AVG(
			CASE WHEN ac.player_id IS NULL THEN
				0
			ELSE
				1
			END
),
		2
) AS fraction
FROM
	playerStartDates AS psd
	LEFT JOIN Activity AS ac ON ac.player_id = psd.player_id
		AND DATE_ADD(
			psd.event_date,
			INTERVAL 1 DAY
) = ac.event_date;
