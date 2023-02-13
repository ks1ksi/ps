select year(o.sales_date) as year, month(o.sales_date) as month, u.gender as gender, count(distinct u.user_id) as users
from online_sale o
join user_info u
on o.user_id = u.user_id
where u.gender is not null
group by year, month, gender
order by year, month, gender;