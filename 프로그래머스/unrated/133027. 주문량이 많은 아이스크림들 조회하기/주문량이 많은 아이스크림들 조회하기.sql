select flavor
from (
    select f.flavor, sum(f.total_order) as sf, sum(j.total_order) as sj
    from first_half f
    join july j
    on f.flavor = j.flavor
    group by f.flavor
    order by sf + sj desc
    limit 3
) t