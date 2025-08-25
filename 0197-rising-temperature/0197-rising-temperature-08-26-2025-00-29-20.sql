-- # Write your MySQL query statement below
-- select w1.id
-- from Weather as w1
-- JOIN Weather as w2
-- -- ON w1.id= w2.id
-- ON YEAR(w1.recordDate) = YEAR(w2.recordDate)
--  AND DAYOFYEAR(w1.recordDate) = DAYOFYEAR(w2.recordDate) + 1
-- -- where YEAR(w1.recordDate) = YEAR(w2.recordDate) and 
-- --     DAYOFYEAR(w1.recordDate) = 1 + DAYOFYEAR(w2.recordDate) and
-- --      w1.temperature > w2.temperature;
-- where w1.temperature> w2.temperature;

# YE SAB FALTU HAI USE DATEDIFF

select w1.id
from weather as w1
JOIN weather as w2 
ON datediff(w1.recordDate, w2.recordDate)=1 -- no need to worry abput the leap year 
where w1.temperature> w2.temperature;
