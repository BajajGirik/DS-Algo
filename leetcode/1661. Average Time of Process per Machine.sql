SELECT
    startActivity.machine_id,
    ROUND(AVG(endActivity.timestamp - startActivity.timestamp), 3) AS "processing_time"
FROM Activity AS startActivity
INNER JOIN Activity AS endActivity
ON
    startActivity.machine_id = endActivity.machine_id AND
    startActivity.process_id = endActivity.process_id
WHERE
    startActivity.activity_type = "start" AND
    endActivity.activity_type = "end"
GROUP BY startActivity.machine_id
