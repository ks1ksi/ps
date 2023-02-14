select p.category, p.price as max_price, p.product_name
from food_product p
join (
    select category, max(price) as max_price
    from food_product
    where category in ('과자', '국', '김치', '식용유')
    group by category
) q on p.category = q.category and p.price = q.max_price
order by max_price desc;