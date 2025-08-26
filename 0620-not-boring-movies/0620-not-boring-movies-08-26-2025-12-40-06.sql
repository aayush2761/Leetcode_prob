# Write your MySQL query statement below

select id, movie,description,rating
from Cinema as c
where c.id%2=1 and c.description != "boring"
order by c.rating desc