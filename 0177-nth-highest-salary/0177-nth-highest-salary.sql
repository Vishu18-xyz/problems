CREATE OR REPLACE FUNCTION NthHighestSalary(N INT) RETURNS TABLE (Salary INT) AS $$
BEGIN
  RETURN QUERY (
    -- Write your PostgreSQL query statement below.
     SELECT MAX(e1.salary)
        FROM Employee e1
        WHERE (
            SELECT COUNT(DISTINCT e2.salary)
            FROM Employee e2
            WHERE e2.salary > e1.salary
        ) = N - 1
      
  );
END;
$$ LANGUAGE plpgsql;