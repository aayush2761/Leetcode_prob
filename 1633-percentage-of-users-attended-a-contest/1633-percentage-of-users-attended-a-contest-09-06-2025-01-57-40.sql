# Write your MySQL query statement below
select r.contest_id, ROUND( ((COUNT(r.user_id)*100.0) / (select COUNT(*) from Users)) ,2) as percentage
from Users as u 
RIGHT JOIN Register as r 
ON u.user_id = r.user_id
GROUP BY r.contest_id
ORDER BY percentage DESC, r.contest_id