module Main where

import System.Exit(exitSuccess)

criba :: [Integer] -> [Integer]
criba (p:xs) = [x | x <- xs, p `noDivide` x]
  where m `noDivide` n = mod n m /= 0

primes :: [Integer]
primes = map head lprimos where lprimos = [2..] : map criba lprimos

primeGen :: Integer -> Integer -> [Integer]
primeGen s e = let xs = ignore s primes
               in select e xs

ignore :: Integer -> [Integer] -> [Integer]
ignore z (y:ys)
    | z > y     = ignore z ys
    | otherwise = (y:ys)

select :: Integer -> [Integer] -> [Integer]
select z (y:ys)
    | z >= y    = y : select z ys
    | otherwise = []
                                        
process :: Int -> IO ()
process 0 = exitSuccess
process n = do
  ss <- getLine
  let [s, e] = ((map read).words) ss
      p'     = primeGen s e
  mapM_ (putStrLn.show) p'
  process (n-1)

main :: IO ()
main = do
  ss <- getLine
  let [n] = ((map read).words) ss
  process n
