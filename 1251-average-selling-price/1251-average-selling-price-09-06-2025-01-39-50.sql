# Write your MySQL query statement below
# avg selling price of each product 

select p.product_id , IFNULL(ROUND( SUM(p.price*u.units) / SUM(u.units)  , 2),0) as average_price
from Prices as p 
LEFT JOIN UnitsSold as u
on p.product_id = u.product_id
-- WHERE u.purchase_date BETWEEN p.start_date and p.end_date
AND u.purchase_date BETWEEN p.start_date and p.end_date
group by p.product_id
order by p.product_id
