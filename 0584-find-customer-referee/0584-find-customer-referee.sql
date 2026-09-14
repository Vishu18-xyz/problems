-- Write your PostgreSQL query statement below
SELECT c.name FROM customer c WHERE referee_id != 2  OR referee_id IS NULL