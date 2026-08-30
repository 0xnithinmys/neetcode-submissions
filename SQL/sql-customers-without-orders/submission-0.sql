SELECT s.name
FROM customers s
WHERE NOT EXISTS (
    SELECT 1
    FROM orders o
    WHERE s.id = o.customer_id
);