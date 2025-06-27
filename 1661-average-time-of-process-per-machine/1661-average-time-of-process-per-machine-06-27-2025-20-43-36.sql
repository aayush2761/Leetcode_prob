# Write your MySQL query statement below

select 
a1.machine_id , ROUND(AVG(-a1.timestamp+ a2.timestamp),3) as processing_time 
from Activity as a1
join Activity as a2 
on a1.machine_id= a2.machine_id
where a1.activity_type="start" and   a2.activity_type = "end"
and a1.process_id = a2.process_id
group by machine_id
