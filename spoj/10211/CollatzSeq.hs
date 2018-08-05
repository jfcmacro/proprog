module Main where

iter :: Int -> Int
iter n
  | n `mod` 2 == 0 = n `div` 2
  | otherwise      = 3 * n + 1

tnpo :: Int -> Int -> IO ()
tnpo 1 t = putStrLn $ show t
tnpo n t = tnpo (iter n) (t + 1)

main :: IO ()
main = do s <- getLine
          let n = read s
          tnpo n 1
