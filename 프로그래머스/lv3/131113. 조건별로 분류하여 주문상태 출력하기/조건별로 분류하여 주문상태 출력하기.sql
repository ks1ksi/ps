select f.order_id, f.product_id, date_format(f.out_date, '%Y-%m-%d') as out_date, o.ot as 출고여부
from food_order f
join (
    select (
        case 
        when out_date is null then '출고미정'
        when out_date <= '2022-05-01' then '출고완료'
        else '출고대기'
        end
    ) as ot,
    order_id
    from food_order
) o
on f.order_id = o.order_id
order by 1 asc;