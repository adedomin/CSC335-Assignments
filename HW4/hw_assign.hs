quickselect :: Ord a => Int -> [a] -> a

quickselect pos (x:xs) 
	| pos < len = quickselect pos ys
	| pos > len = quickselect new_pos zs
	| otherwise = x
	where
		ys  = filter (<x) xs
		zs  = filter (>=x) xs
		len = length ys
		new_pos = pos - (len - 1)
