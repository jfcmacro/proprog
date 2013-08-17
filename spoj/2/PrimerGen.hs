module Main where

import Control.Monad.State
import Data.List((\\))

type StatePrim = StateT [Int] IO

addRelPrime :: Int -> StatePrim ()
addRelPrime n = do
  prim <- get
  let prim' = [ x | x <- prim, n  `mod` x == 0]
  if null prim'
   then put $ prim ++ [n]
   else return $ ()

computePrimesFrom :: Int -> Int -> StatePrim ()
computePrimesFrom m n
  | m >= n      = return $ ()
  | from < n    = do
    addRelPrime m
    computePrimesFrom (m + 1) to

-- 'testLimits'
--
testLimits :: Int -> Int -> StatePrim (Int,Int,Int)
testLimits m n = do
  prim <- get
  let (i,m',n') = if null prim 
                  then (2,m,n) 
                  else let lp = last prim
                       in if lp <= m
                          then (lp,m,n)
                          else if lp <= n
                               then (lp,lp,n)
                               else (lp,lp,lp)
  return $ (i,m',n')
 
printPrimes :: Int -> Int -> StatePrim ()
printPrimes m n  = do
  (i,m',n') <- testLimits m n
  computePrimesFrom i m'
  prim'  <- get
  computePrimesFrom m' n'
  prim'' <- get
  let result = prim'' \\ prim'
  lift $ mapM_ print result >> putStrLn ""

evalPrintPrimes :: Int -> Int -> [Int] -> IO ((),[Int])
evalPrintPrimes m n st = runStateT (printPrimes m n) st

process :: Int -> [Int] -> IO ()
process 1 st = return $ ()
process n st = do
  l <- getLine
  let [m,n] = map read $ words l
  (_,st) evalPrintPrimes m n st
  process (n - 1)

main :: IO ()
main = do
  l <- getLine
  let nc = read l
  process nc []
