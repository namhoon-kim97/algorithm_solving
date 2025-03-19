-- 코드를 입력하세요
SELECT CAR_TYPE, COUNT(*) AS CARS from CAR_RENTAL_COMPANY_CAR 
where OPTIONS like '%통풍시트%' OR OPTIONS LIKE '%열선시트%' OR OPTIONS LIKE '%가죽시트%'
group by car_type
order by car_type