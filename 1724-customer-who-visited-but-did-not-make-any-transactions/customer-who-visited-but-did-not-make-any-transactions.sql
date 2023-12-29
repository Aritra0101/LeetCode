# Write your MySQL query statement below

SELECT DISTINCT customer_id, COUNT(visit_id) AS count_no_trans 
FROM Visits 
WHERE visit_id NOT IN ( SELECT Visits.visit_id FROM Visits JOIN Transactions ON Visits.visit_id = Transactions.visit_id ) 
GROUP BY customer_id;