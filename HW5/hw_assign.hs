min_max :: Ord a => [a] -> Maybe (a, a)

min_max [] = Nothing
min_max (x:xs) = Just $
	foldr (\(x,a) (y,b) -> 
		if x > y then 
			(if a < b then 
				(y, b) 
			else 
				(y, a)) 
		else 
			(if a < b then 
				(x, b) 
			else 
				(x, a))) 
	(x,x) (zip xs xs)

div_min_max'split :: Ord a => [a] -> ([a], [a])
div_min_max'merge :: Ord a => (a,a) -> (a,a) -> (a,a)
div_min_max :: Ord a => [a] -> (a, a)

div_min_max'split xs = (take n xs, drop n xs)
    where 
	n = (length xs) `div` 2

div_min_max'merge (x,a) (y,b) =
	(if x > y then
		(if a < b then
			(y, b)
		else
			(y, a))
	else
		(if a < b then
			(x, b)
		else
			(a, a)))

div_min_max xs
	| (length xs) > 1 = 
		div_min_max'merge 
			(div_min_max left)
			(div_min_max right)
	| otherwise = (xs !! 0, xs !! 0)
	where
	(left, right) = div_min_max'split xs
