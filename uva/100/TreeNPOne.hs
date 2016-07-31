module Main where

iter :: Int -> Int
iter n
  | n `mod` 2 == 0 = n `div` 2
  | otherwise      = 3 * n + 1

tnpo :: Int -> IO ()
tnpo 1 = putStrLn "1"
tnpo n = do
        putStrLn $ show n
        tnpo $ iter n

main :: IO ()
main = do
   s <- getLine
   tnpo (read s)

