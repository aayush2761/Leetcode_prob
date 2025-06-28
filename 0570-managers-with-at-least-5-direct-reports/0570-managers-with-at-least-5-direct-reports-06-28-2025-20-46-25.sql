# Write your MySQL query statement below
select e1.name
from Employee as e1 
join 
Employee as e2 
on e1.id= e2.managerId 
where e1.id != e2.id
group by e2.managerId
having count(*)>4 
