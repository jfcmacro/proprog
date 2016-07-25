module Main where

import Data.Char(isLetter)
import System.Exit(exitSuccess)

type Stack = String

pop :: Stack -> (Char,Stack)
pop [] = error "Stack empty in pop"
pop (x:xs) = (x,xs)

push :: Char -> Stack -> Stack
push c xs = c : xs

expr :: String -> Stack -> (Stack, String)
expr [] s = ([],s)
expr ('(':xs) s = let (s', xs')         = expr xs s
                      (ops,xs'')        = op xs'
                      (s'',(')':xs''')) = expr xs'' s'
                  in (push ops s'', xs''')
expr (x:xs) s
     | isLetter x = (push x s, xs)
     | otherwise  = error "incorrect expre"

isOp :: Char -> Bool
isOp '+' = True
isOp '-' = True
isOp '*' = True
isOp '/' = True
isOp '^' = True
isOp _   = False
           
op :: String -> (Char, String)
op [] = error "This cannot happen"
op (x:xs)
   | isOp x   = (x,xs)
   | otherwise = error "No operator found"

parser :: String -> Stack
parser xs = let (s,_) = expr xs []
            in reverse s

processTimes :: Int -> IO ()
processTimes 0 = exitSuccess
processTimes n = do
  s <- getLine
  putStrLn $ parser s
  processTimes (n-1)

main :: IO ()
main = do
  s <- getLine
  let n = read s
  processTimes n
