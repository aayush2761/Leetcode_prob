# Write your MySQL query statement below

select i1.id
from Weather as i1
join Weather as i2 
on DATE(i1.recordDate) = DATE(i2.recordDate)+1 AND i1.temperature > i2.temperature ;
