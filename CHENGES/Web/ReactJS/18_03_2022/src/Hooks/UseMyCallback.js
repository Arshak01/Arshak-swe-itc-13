import { useRef } from "react";

const useMyCallback = (cb, dplist) => {
  const prdplist = useRef(dplist);
  const prevcb = useRef(cb);
  if (dplist.some((value, index) => prdplist.current[index] !== value)) {
    prdplist.current = dplist;
    prevcb.current = cb;
  }
  return prevcb.current;
};

export default useMyCallback();
