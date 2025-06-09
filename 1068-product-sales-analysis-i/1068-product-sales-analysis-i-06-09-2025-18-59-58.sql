# Write your MySQL query statement below
select p.product_name,e.year,e.price 
from  Product as p
INNER JOIN 
 Sales as e
ON e.product_id= p.product_id;