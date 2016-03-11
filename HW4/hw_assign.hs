hw_assign :: Ord a => Int -> [a] -> a

hw_assign pos (x:xs) 
	| pos < len = hw_assign pos ys
	| pos > len = hw_assign new_pos zs
	| otherwise = x
	where
		ys  = filter (<x) xs
		zs  = filter (>=x) xs
		len = length ys
		new_pos = pos - (len - 1)
