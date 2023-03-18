-- datetime 오름차순 정렬 후 limit 를 이용해 상위 1개만 가지고 온다.
SELECT NAME from ANIMAL_INS
order by DATETIME
limit 1
