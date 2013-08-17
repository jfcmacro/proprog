module Main where

import Monad.Control.State

prim n = [ x | x <- [2 .. n], y <- [2 .. (n-1)], x % y == 0]
