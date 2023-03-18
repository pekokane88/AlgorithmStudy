-- 다중 정렬 문제, 정렬은 우선순위는 왼쪽에서부터 시작된다.
SELECT ANIMAL_ID, NAME, DATETIME from ANIMAL_INS
order by NAME, DATETIME desc
