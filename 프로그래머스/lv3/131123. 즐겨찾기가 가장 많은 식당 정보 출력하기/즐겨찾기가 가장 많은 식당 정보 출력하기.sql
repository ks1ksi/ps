select i.food_type, i.rest_id, i.rest_name, i.favorites
from rest_info i
join (
    select food_type, max(favorites) as favorites
    from rest_info
    group by food_type
) m on i.food_type = m.food_type and i.favorites = m.favorites
order by i.food_type desc;