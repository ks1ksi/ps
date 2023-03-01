select h.history_id,
floor(c.daily_fee * (datediff(h.end_date, h.start_date)+1) / 100 * (100 - ifnull(d.discount_rate, 0))) as fee
from car_rental_company_car c
join car_rental_company_rental_history h
on c.car_id = h.car_id
join (
    select history_id, 
    (
        case 
        when datediff(end_date, start_date)+1 between 7 and 29 then '7일 이상'
        when datediff(end_date, start_date)+1 between 30 and 89 then '30일 이상'
        when datediff(end_date, start_date)+1 >= 90 then '90일 이상'
        else '7일 미만'
        end
    ) as duration_type
    from car_rental_company_rental_history
) dt
on dt.history_id = h.history_id
left join car_rental_company_discount_plan d
on d.duration_type = dt.duration_type and d.car_type = c.car_type
where c.car_type = '트럭'
order by fee desc, h.history_id desc;