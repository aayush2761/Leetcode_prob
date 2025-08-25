# Write your MySQL query statement below
-- use case 

select eu.unique_id as unique_id, en.name
from Employees as en
LEFT JOIN EmployeeUNI as eu  #saare bande chaiye for left 
ON en.id=eu.id
