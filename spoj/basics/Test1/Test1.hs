module Main where

import System.Exit(exitSuccess)

main :: IO ()
main = do
  s <- getLine
  let is = (read s)::Int
  t <- getLine
  let it = read t
  let res = is + it
  putStrLn $ show res
  exitSuccess
