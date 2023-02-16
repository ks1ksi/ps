select p.product_code, (s.total * p.price) as sales
from product p
join (
    select product_id, sum(sales_amount) as total
    from offline_sale
    group by product_id
) s on p.product_id = s.product_id
order by sales desc, p.product_code asc;