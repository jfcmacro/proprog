module Main where

import System.Exit(exitSuccess)

main :: IO ()
main = do s <- getLine
          let i = read s
          if i /= 42 
           then (putStrLn $ show i) >> main
           else exitSuccess
