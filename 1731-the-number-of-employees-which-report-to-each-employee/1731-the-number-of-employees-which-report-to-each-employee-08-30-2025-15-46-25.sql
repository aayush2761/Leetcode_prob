# Write your MySQL query statement below
# id and name of the managers 
select e1.employee_id, e1.name, COUNT(e2.employee_id) as reports_count, ROUND(AVG(e2.age)) as average_age   
from Employees as e1
JOIN Employees as e2
ON e1.employee_id = e2.reports_to
group by employee_id
order by employee_id