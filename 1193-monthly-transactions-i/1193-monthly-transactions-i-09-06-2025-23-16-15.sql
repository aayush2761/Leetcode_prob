# Write your MySQL query statement below


select DATE_FORMAT(trans_date , '%Y-%m') as month , country , 
    COUNT(*) as trans_count ,
    SUM(state= 'approved') as approved_count , # conditional count
    SUM(amount) as trans_total_amount , 
     SUM((state = 'approved') * amount)   as approved_total_amount #cconditional sum 
from Transactions as t
group by month, country
order  by trans_count DESC