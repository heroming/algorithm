# Write your MySQL query statement below
SELECT
    P.id AS id,
    COALESCE(Q.student, P.student) AS student
FROM
    seat AS P
LEFT JOIN
    seat AS Q
ON
    ((P.id + 1) ^ 1) - 1 = Q.id
ORDER BY
    id
